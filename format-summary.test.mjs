import { test } from "node:test";
import assert from "node:assert/strict";
import { formatSummary } from "./format-summary.mjs";

test("empty array returns an empty string", () => assert.equal(formatSummary([]), ""));
test("one item retains its summary", () => assert.equal(formatSummary(["alpha"]), "Summary: alpha"));
test("multiple items retain their summary", () => assert.equal(formatSummary(["alpha", "beta"]), "Summary: alpha, beta"));
test("surrounding whitespace is trimmed from each item", () => {
  assert.equal(formatSummary(["  alpha \t", "\nbeta  ", " gamma delta\r\n"]), "Summary: alpha, beta, gamma delta");
});
