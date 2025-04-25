import time

start_time = time.time()
for i in range(1, 1_000_000_001):
    if i % 100_000_000 == 0:
        print(f"Count reached: {i}")
end_time = time.time()

print(f"Time taken to count from 1 to a billion: {end_time - start_time} seconds")
