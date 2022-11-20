#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_run(void *data) {
    pthread_t pt_id = pthread_self();
    printf("[PTHR: %ld]: New thread started\n", pt_id);

    sleep(3);

    printf("[PTHR: %ld]: Finishing new thread\n", pt_id);

    int ret = 42;
    pthread_exit(&ret);
}

int main() {
    pthread_t thread_id;
    pthread_t main_id = pthread_self();

    printf("[MAIN: %ld]: Starting new thread from main\n", main_id);
    int thread_rc = pthread_create(&thread_id, NULL, thread_run, NULL);
    if (thread_rc != 0) {
        printf("Error creating thread %i\n", thread_rc);
        exit(1);
    }

    int *output;
    pthread_join(thread_id, (void**) &output);
    printf("[MAIN: %ld]: Thread finished, returning %d\n", main_id, *output);

    return 0;
}
