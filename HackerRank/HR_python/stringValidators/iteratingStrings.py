# Testing printing by indices element with slicing in strings

testString = "test"
testEmptyString = ""

lastChar = testString[-1]

print("last characer: {}".format(lastChar))
print("last character directly: {}".format(testString[-1]))
print("index of first element: {}".format(testString.index(str(testString[0]))))
print("index of last element: {}".format(testString.index(str(testString[-1]))))


print()
print(testString.index(testString[-1]))
print(len(testString))