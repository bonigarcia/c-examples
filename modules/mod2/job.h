#ifndef JOB_H
#define JOB_H

#include "people.h"

typedef struct Job {
    Person person;
    char role[MAX_STR];
} Job;

void display_job(Job job);

#endif
