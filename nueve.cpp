#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysinfo.h>

void *thread_function(void *arg) {
    pthread_t tid = pthread_self();
    std::cout << "Hilo ID: " << tid << std::endl;

    // Simular carga de CPU durante al menos 120 segundos
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 120) {
        // Operación pesada para consumir CPU
        for (volatile long i = 0; i < 1000000; ++i);
    }

    pthread_exit(NULL);
}

int main() {
    int num_cores = get_nprocs();
    std::vector<pthread_t> threads(num_cores);

    for (int i = 0; i < num_cores; ++i) {
        int ret = pthread_create(&threads[i], NULL, thread_function, NULL);
        if (ret != 0) {
            std::cerr << "Error al crear el hilo " << i << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_cores; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
