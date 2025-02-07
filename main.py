import asyncio
import time

async def main():
    start_time = time.time()
    await count_async()
    async_duration = time.time() - start_time

    start_time = time.time()
    count_sync()
    sync_duration = time.time() - start_time
    print(f"Async function took {async_duration:.2f} seconds")
    print(f"Sync function took {sync_duration:.2f} seconds")

async def count_async():
    for i in range(1, 100000001):
        if i % 100000 == 0:
            print(f"Counted to {i} asynchronously")

def count_sync():
    for i in range(1, 100000001):
        if i % 100000 == 0:
            print(f"Counted to {i} synchronously")

if __name__ == "__main__":
    asyncio.run(main())