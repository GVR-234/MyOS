import { test } from "node:test";
import assert from "node:assert/strict";
import { formatSummary } from "./format-summary.mjs";

test("one item retains its summary", () => assert.equal(formatSummary(["alpha"]), "Summary: alpha"));
test("multiple items retain their summary", () => assert.equal(formatSummary(["alpha", "beta"]), "Summary: alpha, beta"));
