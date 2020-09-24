/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"
#include "../includes/constants.h"

//Scheduler::Scheduler(std::queue<PCB> &queue, bool preemptive, int time_slice)
//: Scheduler::ready_q(&queue), Scheduler::preemptive(preemptive), Scheduler::time_slice(time_slice){}

void Scheduler::add(PCB p){
	ready_q->push(p);
}

PCB Scheduler::getNext(){
	PCB p = ready_q->front();
	ready_q->pop();
	return p;
}

bool Scheduler::isEmpty(){
	if (ready_q->size() == 0){
		return true;
	}
	else {
		return false;
	}
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	if(p.remaining_cpu_time == 0 || (preemptive == true && time_slice > tick_count))
		return true;
	else
		return false;
}



