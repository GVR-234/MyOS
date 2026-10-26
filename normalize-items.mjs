export function normalizeItems(items) {
  return items.map((item) => item.trim()).filter((item) => item.length > 0);
}
