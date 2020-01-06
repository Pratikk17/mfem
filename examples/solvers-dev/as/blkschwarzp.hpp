
#pragma once

#include "mfem.hpp"
#include <fstream>
#include <iostream>
#include "schwarzp.hpp"
using namespace std;
using namespace mfem;


class BlkParSchwarzSmoother : virtual public Solver {
private:
   MPI_Comm comm;
   int nrpatch;
   int maxit = 1;
   double theta = 1.0;
   Array<int> host_rank;
   // Array<PetscLinearSolver * > PatchInv;
   Array<UMFPackSolver * > PatchInv;
   Array<KLUSolver * > PatchInvKLU;
   Array<SparseMatrix * > PatchMat;
   /// The linear system matrix
   Array2D<HypreParMatrix*> blockA;
   BlockOperator * bop;
   Array2D<PatchRestriction *> R;
   Array2D<par_patch_assembly *> P;
   BlockOperator * blk = nullptr;
public:
   // BlkParSchwarzSmoother(ParMesh * cpmesh_, int ref_levels_,ParFiniteElementSpace *fespace_,
   //                       Array2D<HypreParMatrix*> blockA_);
   BlkParSchwarzSmoother(ParMesh * cpmesh_, int ref_levels_,ParFiniteElementSpace *fespace_,
                         BlockOperator * bop_);                      
   void SetNumSmoothSteps(const int iter) {maxit = iter;}
   void SetDumpingParam(const double dump_param) {theta = dump_param;}
  
   virtual void SetOperator(const Operator &op) {}
   virtual void Mult(const Vector &r, Vector &z) const;
   virtual ~BlkParSchwarzSmoother();
};