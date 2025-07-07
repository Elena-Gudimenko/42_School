/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:21:33 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/07 18:35:57 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#define NUM_ITERATIONS 1000000
/*
int counter = 0;             // Общая переменная
pthread_mutex_t mutex;       // Мьютекс для синхронизации

void* increment(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);   // Захватываем мьютекс
        counter++;                    // Увеличиваем общий счётчик
        pthread_mutex_unlock(&mutex); // Освобождаем мьютекс
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL); // Инициализируем мьютекс

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex); // Удаляем мьютекс

    printf("Итоговое значение счётчика: %d\n", counter);
    return 0;
}
*/

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        counter++; // Нет синхронизации!
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Итоговое значение счётчика: %d\n", counter);
    return 0;
}