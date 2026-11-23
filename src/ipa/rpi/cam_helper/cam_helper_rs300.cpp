/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Camera helper for the rs300 (Mini2 / WN2) thermal camera module.
 *
 * The module has no exposure or gain settings and no embedded data. The
 * driver accepts the exposure, gain and blanking controls and ignores them,
 * so this helper reports unity analogue gain and no integration margin.
 */

#include "cam_helper.h"

using namespace RPiController;

class CamHelperRs300 : public CamHelper
{
public:
	CamHelperRs300();
	uint32_t gainCode(double gain) const override;
	double gain(uint32_t gainCode) const override;
};

CamHelperRs300::CamHelperRs300()
	: CamHelper({}, 0)
{
}

uint32_t CamHelperRs300::gainCode([[maybe_unused]] double gain) const
{
	return 1;
}

double CamHelperRs300::gain([[maybe_unused]] uint32_t gainCode) const
{
	return 1.0;
}

static CamHelper *create()
{
	return new CamHelperRs300();
}

static RegisterCamHelper reg("rs300", &create);
