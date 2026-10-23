# MyOS local formatter pilot

A dependency-free Node formatter for the disposable launch-acceptance workflow.
The component accepts arrays of strings. `formatSummary` uses the pure
`normalizeItems` helper to trim surrounding whitespace and omit empty results
without mutating the input. Remaining items retain their order, duplicates,
case and internal whitespace. The output is `Summary: ` followed by items
joined with comma-space, or an empty string when no items remain.

Run the regression tests with `node --test`.
The approved workflow runs them in the pinned offline Docker image.

`fixtures/probe.bin` is a byte-integrity acceptance fixture containing exactly
four bytes: `[0, 1, 2, 255]`. A regression test reads it relative to the test
module and checks both its length and complete byte contents, including NUL
and the non-UTF-8 byte 255.

The acceptance workflow requires independent testing, security and code review,
separate operator review at every checkpoint, and a separately reviewed draft
PR to GVR-234/MyOS. No merge or deployment is included.
