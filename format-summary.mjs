import { normalizeItems } from "./normalize-items.mjs";

export function formatSummary(items) {
  const normalizedItems = normalizeItems(items);
  if (normalizedItems.length === 0) return "";
  return `Summary: ${normalizedItems.join(", ")}`;
}
