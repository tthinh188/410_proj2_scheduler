/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
#include "../includes/constants.h"

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

int minIndex(std::queue<PCB> *q, int sortedIndex){
	int min_index = -1;
	int min_val = 9999;
	for (int i =0; i < q->size(); i++){
		PCB curr = q->front();
		q->pop();
		if (curr.remaining_cpu_time <= min_val && i <= sortedIndex){
			min_index = i;
			min_val = curr.remaining_cpu_time;
		}
		q->push(curr);
	}
	return min_index;
}

void insertMinToEnd(std::queue<PCB> *q, int min_index){
	PCB min_val;
	for (int i = 0; i< q->size(); i++){
		PCB curr = q->front();
		q->pop();
		if (i != min_index){
			q->push(curr);
		}
		else{
			min_val = curr;
		}
	}
	q->push(min_val);
}

void Scheduler_SRTF::sort(){
	for (int i =1; i< ready_q->size(); i++){
		int min_index = minIndex(ready_q, i);
		insertMinToEnd(ready_q, min_index);
	}
}
