/*
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <stddef.h>
#include "drm-uapi/asahi_drm.h"

/* The kernel header defines one struct per command, its optional parts
 * appended in order. A command may end after any of them; the kernel reads
 * the parts it omits as zero, and kernels that predate a part refuse a
 * command that carries it. These are the sizes a command sends by what it
 * carries, taken from that one definition.
 */

/* Render: the base command, then prior_vdm/prior_cdm (exact priors), then
 * ray_query[2], then the tiling half's stage prefixes. */
#define AGX_DRM_RENDER_SIZE_BASE offsetof(struct drm_asahi_cmd_render, prior_vdm)
#define AGX_DRM_RENDER_SIZE_PRIOR offsetof(struct drm_asahi_cmd_render, ray_query)
#define AGX_DRM_RENDER_SIZE_RAY_QUERY                                          \
   offsetof(struct drm_asahi_cmd_render, ta_cdm_barrier)
#define AGX_DRM_RENDER_SIZE_FULL sizeof(struct drm_asahi_cmd_render)

/* Compute: the base command, then scs_layout, prior_vdm/prior_cdm and the
 * ray-query state. */
#define AGX_DRM_COMPUTE_SIZE_BASE                                              \
   offsetof(struct drm_asahi_cmd_compute, scs_layout)
#define AGX_DRM_COMPUTE_SIZE_FULL sizeof(struct drm_asahi_cmd_compute)
