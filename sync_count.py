import time

start_time = time.time()
count = 0

for i in range(1, 1000000001):
    count += 1
    
    if count % 100000000 == 0:
        print(f"Count reached: {count}")

end_time = time.time()

print(f"Time taken to count from 1 to a billion: {end_time - start_time} seconds")
