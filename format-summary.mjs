export function formatSummary(items) {
  if (items.length === 0) return "";
  return `Summary: ${items.join(", ")}`;
}
