/*
    Copyright (C) 2011 Angelo Arrifano <miknix@gmail.com>
		- Improved timer0 API, add register and unregister functions

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// *************************************************************************************************
//
//	Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
//	 
//	 
//	  Redistribution and use in source and binary forms, with or without 
//	  modification, are permitted provided that the following conditions 
//	  are met:
//	
//	    Redistributions of source code must retain the above copyright 
//	    notice, this list of conditions and the following disclaimer.
//	 
//	    Redistributions in binary form must reproduce the above copyright
//	    notice, this list of conditions and the following disclaimer in the 
//	    documentation and/or other materials provided with the   
//	    distribution.
//	 
//	    Neither the name of Texas Instruments Incorporated nor the names of
//	    its contributors may be used to endorse or promote products derived
//	    from this software without specific prior written permission.
//	
//	  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//	  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//	  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//	  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//	  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//	  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//	  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//	  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//	  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//	  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//	  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *************************************************************************************************

#ifndef TIMER_H_
#define TIMER_H_

// *************************************************************************************************
// Include section


// *************************************************************************************************
// Prototypes section
extern void Timer0_Init(void);
extern void Timer0_Start(void);
extern void Timer0_Stop(void);
extern void Timer0_A1_Start(u16 ticks);
extern void Timer0_A1_Stop(void);
extern void Timer0_A1_Register(void (*callback)(void));
extern void Timer0_A1_Unregister(void (*callback)(void));
extern void Timer0_A3_Start(u16 ticks);
extern void Timer0_A3_Stop(void);
extern void Timer0_A4_Delay(u16 ticks);
extern void (*fptr_Timer0_A3_function)(void);
#ifdef CONFIG_USE_GPS
extern void (*fptr_Timer0_A1_function)(void);
#endif


// *************************************************************************************************
// Defines section
struct cbList {
	void (*fn)(void);
	struct cbList *next;
};
struct timer
{
	// Timer0_A1 periodic delay
	u16		timer0_A1_ticks;
		// Timer0_A3 periodic delay
	u16		timer0_A3_ticks;
	// callback queue
	struct cbList *queue;
};
extern struct timer sTimer;

// Trigger reset when all buttons are pressed
#define BUTTON_RESET_SEC		(3u)

// *************************************************************************************************
// Global Variable section


// *************************************************************************************************
// Extern section



#endif /*TIMER_H_*/
