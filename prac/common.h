#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime(){

    return (double) t.tv_sec + (double) t.tv_usec/le6;
    
}
