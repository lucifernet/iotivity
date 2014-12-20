// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_DEBUG_PROFILER_H
#define BASE_DEBUG_PROFILER_H
#pragma once

#include <string>

#include "base/base_export.h"
#include "base/basictypes.h"

// The Profiler functions allow usage of the underlying sampling based
// profiler. If the application has not been built with the necessary
// flags (-DENABLE_PROFILING and not -DNO_TCMALLOC) then these functions
// are noops.
namespace base {
namespace debug {

// Start profiling with the supplied name.
// {pid} will be replaced by the process' pid and {count} will be replaced
// by the count of the profile run (starts at 1 with each process).
BASE_EXPORT void StartProfiling(const std::string& name);

// Stop profiling and write out data.
BASE_EXPORT void StopProfiling();

// Force data to be written to file.
BASE_EXPORT void FlushProfiling();

// Returns true if process is being profiled.
BASE_EXPORT bool BeingProfiled();

// Reset profiling after a fork, which disables timers.
BASE_EXPORT void RestartProfilingAfterFork();

// Returns true iff this executable is instrumented with the Syzygy profiler.
BASE_EXPORT bool IsBinaryInstrumented();

// There's a class of profilers that use "return address swizzling" to get a
// hook on function exits. This class of profilers uses some form of entry hook,
// like e.g. binary instrumentation, or a compiler flag, that calls a hook each
// time a function is invoked. The hook then switches the return address on the
// stack for the address of an exit hook function, and pushes the original
// return address to a shadow stack of some type. When in due course the CPU
// executes a return to the exit hook, the exit hook will do whatever work it
// does on function exit, then arrange to return to the original return address.
// This class of profiler does not play well with programs that look at the
// return address, as does e.g. V8. V8 uses the return address to certain
// runtime functions to find the JIT code that called it, and from there finds
// the V8 data structures associated to the JS function involved.
// A return address resolution function is used to fix this. It allows such
// programs to resolve a location on stack where a return address originally
// resided, to the shadow stack location where the profiler stashed it.
typedef uintptr_t (*ReturnAddressLocationResolver)(
    uintptr_t return_addr_location);

// If this binary is instrumented and the instrumentation supplies a return
// address resolution function, finds and returns the address resolution
// function. Otherwise returns NULL.
BASE_EXPORT ReturnAddressLocationResolver
    GetProfilerReturnAddrResolutionFunc();

}  // namespace debug
}  // namespace base

#endif  // BASE_DEBUG_DEBUGGER_H
