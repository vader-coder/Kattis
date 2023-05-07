#remove duplicates from sorted array

arr = input().split()
elements = len(arr)
out = []
prev = None
for i in range(len(arr)):
  if (i==0):
    out.append(arr[i])
    prev = arr[i]
  else:
    if arr[i] != prev:
      out.append(arr[i])
      prev = arr[i]

print(str(out))