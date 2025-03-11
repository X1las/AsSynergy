import multiprocessing as mp


def count_to_high_number(start, end, q):
    count = 0
    for i in range(start, end):
        count += 1
    q.put(count)

if __name__ == '__main__':
    high_number = 10000000
    num_cores = mp.cpu_count()
    chunk_size = high_number // num_cores

    processes = []
    queues = []

    for i in range(num_cores):
            q = mp.Queue()
            start = i * chunk_size
            end = (i + 1) * chunk_size if i != num_cores - 1 else high_number
            p = mp.Process(target=count_to_high_number, args=(start, end, q))
            processes.append(p)
            queues.append(q)
            p.start()
    
    total_count = 0
    for q in queues:
        total_count += q.get()
    
    for p in processes:
        p.join()
    
    print(f'Total count: {total_count}')