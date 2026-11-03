import { test } from "node:test";
import assert from "node:assert/strict";
import { formatSummary } from "./format-summary.mjs";

test("empty array returns an empty string", () => assert.equal(formatSummary([]), ""));
test("one item retains its summary", () => assert.equal(formatSummary(["alpha"]), "Summary: alpha"));
test("multiple items retain their summary", () => assert.equal(formatSummary(["alpha", "beta"]), "Summary: alpha, beta"));

test("omitted and undefined separator options retain the default", () => {
  const items = ["alpha", "beta"];
  for (const options of [undefined, {}, { separator: undefined }]) {
    assert.equal(formatSummary(items, options), "Summary: alpha, beta");
  }
});

test("custom separator appears at every boundary without a trailing separator", () => {
  assert.equal(formatSummary(["alpha", "beta"], { separator: " | " }), "Summary: alpha | beta");
  assert.equal(formatSummary(["alpha", "beta", "gamma"], { separator: " | " }), "Summary: alpha | beta | gamma");
});

test("empty string separator concatenates items", () => {
  assert.equal(formatSummary(["alpha", "beta"], { separator: "" }), "Summary: alphabeta");
});

test("separator text is inserted literally", () => {
  assert.equal(formatSummary(["alpha", "beta"], { separator: " $&.*\n " }), "Summary: alpha $&.*\n beta");
});

test("literal separators preserve UTF-16 code units, substitution tokens and matching item text", () => {
  for (const separator of [
    "0", "false", "null", "undefined", "alpha", "Summary: ",
    "$`$'$$$&", "<b>&</b>", "\uFEFF", "\u2028\u2029", "\uD800", "\uDC00",
  ]) {
    assert.equal(formatSummary([], { separator }), "");
    assert.equal(formatSummary(["alpha"], { separator }), "Summary: alpha");
    assert.equal(
      formatSummary(["alpha", "", "alpha"], { separator }),
      "Summary: alpha" + separator + separator + "alpha",
    );
  }
});

test("valid separators preserve empty and single-item outputs", () => {
  for (const options of [undefined, {}, { separator: undefined }, { separator: " | " }, { separator: "" }]) {
    assert.equal(formatSummary([], options), "");
    assert.equal(formatSummary(["alpha"], options), "Summary: alpha");
  }
});

for (const [label, separator] of [
  ["null", null],
  ["number", 0],
  ["nonzero number", 42],
  ["NaN", NaN],
  ["positive infinity", Infinity],
  ["negative infinity", -Infinity],
  ["boolean", false],
  ["true boolean", true],
  ["object", {}],
  ["array", []],
  ["populated array", [" | "]],
  ["boxed string", new String(" | ")],
  ["empty boxed string", new String("")],
  ["symbol", Symbol("separator")],
  ["bigint", 1n],
  ["zero bigint", 0n],
  ["function", () => " | "],
]) {
  test(`${label} separator throws TypeError for every array length`, () => {
    for (const items of [[], ["alpha"], ["alpha", "beta"]]) {
      assert.throws(() => formatSummary(items, { separator }), TypeError);
    }
  });
}

test("custom formatting does not mutate inputs or affect subsequent defaults", () => {
  const items = Object.freeze(["alpha", "beta"]);
  const options = Object.freeze({ separator: " | " });
  assert.equal(formatSummary(items, options), "Summary: alpha | beta");
  assert.deepEqual(items, ["alpha", "beta"]);
  assert.deepEqual(options, { separator: " | " });
  assert.equal(formatSummary(items), "Summary: alpha, beta");
});

test("valid formatting succeeds after an invalid separator is rejected", () => {
  assert.throws(() => formatSummary(["alpha", "beta"], { separator: null }), TypeError);
  assert.equal(formatSummary(["alpha", "beta"], { separator: "" }), "Summary: alphabeta");
  assert.equal(formatSummary(["alpha", "beta"]), "Summary: alpha, beta");
});

test("separator is read once per call", () => {
  let reads = 0;
  const options = {
    get separator() {
      reads += 1;
      return " | ";
    },
  };
  assert.equal(formatSummary(["alpha", "beta"], options), "Summary: alpha | beta");
  assert.equal(reads, 1);
});

test("empty-string items retain the prefix and all separator boundaries", () => {
  for (const options of [undefined, {}, { separator: " | " }, { separator: "" }]) {
    assert.equal(formatSummary([""], options), "Summary: ");
  }
  assert.equal(formatSummary(["", "", ""]), "Summary: , , ");
  assert.equal(formatSummary(["", "", ""], { separator: "|" }), "Summary: ||");
  assert.equal(formatSummary(["", "middle", ""], { separator: "|" }), "Summary: |middle|");
  assert.equal(formatSummary(["", "", ""], { separator: "" }), "Summary: ");
});

test("whitespace, control and Unicode separators are preserved literally", () => {
  for (const [separator, expected] of [
    [" ", "Summary: a b c"],
    ["\t", "Summary: a\tb\tc"],
    ["\r\n", "Summary: a\r\nb\r\nc"],
    ["\0", "Summary: a\0b\0c"],
    ["🧵", "Summary: a🧵b🧵c"],
    ["e\u0301", "Summary: ae\u0301be\u0301c"],
  ]) {
    assert.equal(formatSummary(["a", "b", "c"], { separator }), expected);
  }
});

test("invalid object separators are rejected without invoking coercion hooks", () => {
  let coercions = 0;
  const coerce = () => {
    coercions += 1;
    throw new Error("separator coercion must not run");
  };
  const separator = {
    [Symbol.toPrimitive]: coerce,
    toString: coerce,
    valueOf: coerce,
  };
  for (const items of [[], ["alpha"], ["alpha", "beta"]]) {
    assert.throws(() => formatSummary(items, { separator }), TypeError);
  }
  assert.equal(coercions, 0);
});

test("reused options reflect current separators and recover after rejection", () => {
  const items = Object.freeze(["alpha", "beta"]);
  const options = { separator: " | " };
  assert.equal(formatSummary(items, options), "Summary: alpha | beta");
  options.separator = "";
  assert.equal(formatSummary(items, options), "Summary: alphabeta");
  options.separator = null;
  assert.throws(() => formatSummary(items, options), TypeError);
  delete options.separator;
  assert.equal(formatSummary(items, options), "Summary: alpha, beta");
  options.separator = ":";
  assert.equal(formatSummary(items, options), "Summary: alpha:beta");
  assert.deepEqual(options, { separator: ":" });
  assert.equal(formatSummary(items), "Summary: alpha, beta");
});
