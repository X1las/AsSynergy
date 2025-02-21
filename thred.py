import threading
import time

counting_to = 100000000

threads = []
thread_count = 4

def count_sync():
    for i in range(1, counting_to+1):
        if i % int(counting_to/10) == 0:
            print(f"Counted to {i}")

def thread_counting(n):
    global counter
    counter = 0
    time.sleep(1)

    for i in range(1, n+1):
        counter += 1
        if i % int(n/10) == 0:
            print(f"Counted to {counter}")


start = time.time()
count_sync()
end = time.time()

print("total time:", end-start)

start = time.time()
for i in range(thread_count):
    threads.append(threading.Thread(target=thread_counting, args=(int(counting_to/thread_count),)))
    threads[i].start()

print("threads started!")

for thread in threads:
    thread.join()

end = time.time()
print("total time:", end-start)


