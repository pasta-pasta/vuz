import time
import random

def simple(arr):
    # Simple selection sort
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubble(arr):
    # Bubble sort
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def insertion(arr):
    # Insertion sort
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr


def timer(arr, func):
    # Counts time of a sorting function
    start = time.time()
    result = func(arr.copy())  
    end = time.time()
    print(f"{func.__name__} потратила {end - start} секунд.")
    return result, end-start

def main():
    arr = [random.randint(0, 10000) for _ in range(10)]
    print(f"Исходный массив: {arr}")
    simple_sort_result, simple_sort = timer(arr, simple)
    bubble_sort_result, bubble_sort = timer(arr, bubble)
    insertion_sort_result, insertion_sort = timer(arr, insertion)
    print(simple_sort_result, bubble_sort_result, insertion_sort_result)
    best = min(simple_sort, bubble_sort, insertion_sort)
    print(f"Наименьший результат: {best} у функции {'simple' if best == simple_sort else 'bubble' if best == bubble_sort else 'insertion'}")

if __name__ == "__main__":
    main()