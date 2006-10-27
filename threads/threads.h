/*
 * Copyright (c) 2003, 2006 Matteo Frigo
 * Copyright (c) 2003, 2006 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __THREADS_H__
#define __THREADS_H__

#include "ifftw.h"
#include "ct.h"
#include "hc2hc.h"

typedef struct {
     int min, max, thr_num;
     void *data;
} spawn_data;

typedef void *(*spawn_function) (spawn_data *);

void X(spawn_loop)(int loopmax, int nthreads,
		   spawn_function proc, void *data);
int X(ithreads_init)(void);
void X(threads_cleanup)(void);

/* configurations */

void X(dft_thr_vrank_geq1_register)(planner *p);
void X(rdft_thr_vrank_geq1_register)(planner *p);
void X(rdft2_thr_vrank_geq1_register)(planner *p);

ct_solver *X(mksolver_ct_threads)(size_t size, INT r, int dec, ct_mkinferior mkcldw);
hc2hc_solver *X(mksolver_hc2hc_threads)(size_t size, INT r, hc2hc_mkinferior mkcldw);

void X(threads_conf_standard)(planner *p);
void X(threads_register_hooks)(void);
void X(threads_unregister_hooks)(void);
#endif /* __THREADS_H__ */
