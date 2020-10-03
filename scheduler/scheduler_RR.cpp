/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 25, 2020
 *      Author: Thinh Phan
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	// switch if job done
	if (p.remaining_cpu_time <= 0)
		return true;

	//switch when reach the number of clock ticks
	else if (preemptive && (p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0) {
		return true;
	}

	else {
		return false;
	}
}

void Scheduler_RR::sort(){ }
