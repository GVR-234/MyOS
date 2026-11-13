export function formatSummary(items) {
  if (items.length === 0) return "";
  const trimmedItems = items.map(item => typeof item === "string" ? item.trim() : item);
  return `Summary: ${trimmedItems.join(", ")}`;
}
