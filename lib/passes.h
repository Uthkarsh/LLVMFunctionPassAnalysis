#pragma once

#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/CallSite.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/Analysis/CallGraphSCCPass.h"

using namespace llvm;

namespace cs565 {
	struct PrettyPrint : public FunctionPass {
		static char ID;
		PrettyPrint() : FunctionPass(ID) {}
		
		virtual bool runOnFunction(Function &F);
		
		virtual void getAnalysisUsage(AnalysisUsage &Info) const;
	};
}
