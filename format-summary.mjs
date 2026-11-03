export function formatSummary(items, options = {}) {
  const { separator = ", " } = options;
  if (typeof separator !== "string") throw new TypeError("separator must be a string");
  if (items.length === 0) return "";
  return `Summary: ${items.join(separator)}`;
}
