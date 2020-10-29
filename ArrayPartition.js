export let ArrayPartition = (array, pivot) => ({
	left: () => array.slice(0, pivot),
	middle: () => array.get(pivot),
	right: () => array.slice(pivot + 1, array.length),
});
