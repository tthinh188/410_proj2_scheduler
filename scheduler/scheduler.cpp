/*
 * scheduler.cpp
 *
 *  Created on: Sep 24, 2020
 *      Author: Thinh Phan
 */

#include "../includes/scheduler.h"

// add job to queue and sort
void Scheduler::add(PCB p){
	ready_q->push(p);
	sort();
}

// get next job from queue
PCB Scheduler::getNext(){
	PCB p = ready_q->front();
	ready_q->pop();
	return p;
}

// no queue to process
bool Scheduler::isEmpty(){
	return ready_q->size() == 0;
}


bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	// switch when job done.
	return p.remaining_cpu_time <= 0;
}



