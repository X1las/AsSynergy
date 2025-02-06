import asyncio

async def main():
    print("Hello, Asyncio!")
    await asyncio.sleep(1)
    print("Goodbye, Asyncio!")

if __name__ == "__main__":
    asyncio.run(main())