#ifndef _DYNAMIC_CBR_H_
#define _DYNAMIC_CBR_H_

#include <memory>

#include "vcfr.h"

class Buckets;
class CanonicalCards;
class CardAbstraction;
class HandTree;
class Node;

class DynamicCBR : public VCFR {
public:
  DynamicCBR(const CardAbstraction &ca, const BettingAbstraction &ba, const CFRConfig &cc,
	     const Buckets &buckets, const BettingTree *betting_tree, int num_threads);
  DynamicCBR(void);
  ~DynamicCBR(void);
  std::shared_ptr<double []> Compute(Node *node, std::shared_ptr<double []> *reach_probs, int gbd,
				     HandTree *hand_tree, int root_bd_st, int root_bd,
				     int target_p, bool cfrs, bool zero_sum, bool current,
				     bool purify_opp);
private:
  std::shared_ptr<double []> Compute(Node *node, int p, const std::shared_ptr<double []> &opp_probs,
				     int gbd, HandTree *hand_tree, int root_bd_st, int root_bd);

  bool cfrs_;
};

#endif
