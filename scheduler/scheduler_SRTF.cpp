/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 24, 2019
 *      Author: Thinh Phan
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
#include <algorithm>

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	if (p.remaining_cpu_time <= 0){
		return true;
	}
	// switch if a faster job in queue
	else if (p.remaining_cpu_time > ready_q->front().remaining_cpu_time && !ready_q->empty()){
		return true;
	}
	else{
		return false;
	}
}

void Scheduler_SRTF::sort(){

	int q_size = ready_q->size();

	// convert to vector to use std sort
	std::vector<PCB> v;
		for (int i =0; i< q_size; i++){
			v.push_back(ready_q->front());
			ready_q->pop();
		}

		std::sort(v.begin(),v.end(), [] (PCB p1, PCB p2){
			// ascending order of remaining cpu time
			return p1.remaining_cpu_time < p2.remaining_cpu_time;
		});

		// put sorted PCB back to the queue
		for (int i =0; i< q_size; i++){
			ready_q->push(v.front());
			v.erase(v.begin());
		}
}
