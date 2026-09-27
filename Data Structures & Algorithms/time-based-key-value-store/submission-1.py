class TimeMap:

    def __init__(self):
        self.dictionary = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.dictionary:
            self.dictionary[key] = []
        self.dictionary[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        value_timestamps_array = self.dictionary.get(key, [])
        l = 0
        r = len(value_timestamps_array) - 1
        result = ""
        while l <= r:
            mid = (l + r) // 2;
            if value_timestamps_array[mid][1] <= timestamp:
                result = value_timestamps_array[mid][0]
                l = mid + 1
            else:
                r = mid - 1
        return result