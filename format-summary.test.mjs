import { test } from "node:test";
import assert from "node:assert/strict";
import { readFile } from "node:fs/promises";
import { formatSummary } from "./format-summary.mjs";
import { normalizeItems } from "./normalize-items.mjs";

test("empty array returns an empty string", () => assert.equal(formatSummary([]), ""));
test("one item retains its summary", () => assert.equal(formatSummary(["alpha"]), "Summary: alpha"));
test("multiple items retain their summary", () => assert.equal(formatSummary(["alpha", "beta"]), "Summary: alpha, beta"));

test("surrounding whitespace is trimmed and empty results omitted", () => {
  assert.equal(formatSummary([" alpha ", " ", "beta "]), "Summary: alpha, beta");
});

test("Unicode surrounding whitespace is trimmed and empty results omitted", () => {
  assert.equal(formatSummary(["\u00a0alpha\u00a0", "\u2003", "beta"]), "Summary: alpha, beta");
});

test("whitespace-only items return an empty string", () => {
  assert.equal(formatSummary([" ", "\t", "\n", "\r\n"]), "");
});

test("empty strings are omitted", () => {
  assert.equal(formatSummary(["", "alpha", ""]), "Summary: alpha");
  assert.equal(formatSummary(["", ""]), "");
});

test("tabs and newlines surrounding items are trimmed", () => {
  assert.equal(formatSummary(["\talpha\n", "\r\nbeta\t"]), "Summary: alpha, beta");
});

test("internal whitespace, order, duplicates and case are preserved", () => {
  assert.equal(
    formatSummary([" Beta ", "alpha  gamma", "Beta", "a\tb"]),
    "Summary: Beta, alpha  gamma, Beta, a\tb",
  );
});

test("normalization returns a new array without mutating input", () => {
  const items = Object.freeze([" alpha ", " ", "beta "]);
  const normalized = normalizeItems(items);
  assert.deepEqual(normalized, ["alpha", "beta"]);
  assert.notStrictEqual(normalized, items);
  assert.equal(formatSummary(items), "Summary: alpha, beta");
  assert.deepEqual(items, [" alpha ", " ", "beta "]);
});

test("acceptance fixture contains exactly bytes 0, 1, 2, 255", async () => {
  const bytes = await readFile(new URL("./fixtures/probe.bin", import.meta.url));
  assert.equal(bytes.length, 4);
  assert.deepEqual(bytes, Buffer.from([0, 1, 2, 255]));
});
