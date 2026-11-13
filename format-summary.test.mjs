import { test } from "node:test";
import assert from "node:assert/strict";
import { formatSummary } from "./format-summary.mjs";

test("empty array returns an empty string", () => assert.equal(formatSummary([]), ""));
test("one item retains its summary", () => assert.equal(formatSummary(["alpha"]), "Summary: alpha"));
test("multiple items retain their summary", () => assert.equal(formatSummary(["alpha", "beta"]), "Summary: alpha, beta"));

test("trims leading and trailing whitespace from each string", () => {
  assert.equal(formatSummary(["  alpha  ", "\tbeta\n"]), "Summary: alpha, beta");
});

test("preserves internal whitespace", () => {
  assert.equal(formatSummary(["  alpha  beta  ", "\tgamma\tdelta\nepsilon\n"]), "Summary: alpha  beta, gamma\tdelta\nepsilon");
});

test("retains whitespace-only items as empty positions", () => {
  assert.equal(formatSummary([" ", "beta", "\t"]), "Summary: , beta, ");
  assert.equal(formatSummary(["   "]), "Summary: ");
});

test("does not mutate caller-owned items", () => {
  const items = Object.freeze(["  alpha  ", "\tbeta\n"]);
  assert.equal(formatSummary(items), "Summary: alpha, beta");
  assert.deepEqual(items, ["  alpha  ", "\tbeta\n"]);
});

test("preserves non-string join coercion", () => {
  assert.equal(formatSummary([1, null, undefined, " beta "]), "Summary: 1, , , beta");
});

test("uses JavaScript boundary whitespace semantics without stripping content", () => {
  assert.equal(formatSummary(["\u00a0\ufeffalpha\u2028", "\u2029beta\u3000"]), "Summary: alpha, beta");
  assert.equal(formatSummary([" \u200balpha\u200b ", " a\u00a0b "]), "Summary: \u200balpha\u200b, a\u00a0b");
});

test("retains empty entries and stable results across repeated calls", () => {
  const items = Object.freeze(["", " \t\n", " alpha ", ""]);
  assert.equal(formatSummary(items), "Summary: , , alpha, ");
  assert.equal(formatSummary([]), "");
  assert.equal(formatSummary(items), "Summary: , , alpha, ");
  assert.deepEqual(items, ["", " \t\n", " alpha ", ""]);
});

test("leaves whitespace produced by non-string coercion intact", () => {
  const object = { toString: () => "  object  " };
  assert.equal(formatSummary([false, 0, 2n, object, new String(" boxed "), " padded "]),
    "Summary: false, 0, 2,   object  ,  boxed , padded");
});

test("preserves join failures and remains usable after an error", () => {
  const failure = new Error("coercion failed");
  const object = { toString() { throw failure; } };
  assert.throws(() => formatSummary([object]), error => error === failure);
  assert.throws(() => formatSummary([Symbol("item")]), TypeError);
  assert.equal(formatSummary([" alpha "]), "Summary: alpha");
});

test("preserves sparse array positions", () => {
  const items = new Array(3);
  items[1] = " beta ";
  assert.equal(formatSummary(items), "Summary: , beta, ");
  assert.equal(0 in items, false);
  assert.equal(2 in items, false);
});
