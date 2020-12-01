
/*
 * Copyright (C) Roman Arutyunyan
 * Copyright (C) Winshining
 */


#ifndef _NGX_RTMP_CODEC_H_INCLUDED_
#define _NGX_RTMP_CODEC_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include "ngx_rtmp.h"


/* AVC NAL unit types */
enum {
    NGX_RTMP_NALU_SLICE             = 1,
    NGX_RTMP_NALU_DPA               = 2,
    NGX_RTMP_NALU_DPB               = 3,
    NGX_RTMP_NALU_DPC               = 4,
    NGX_RTMP_NALU_IDR               = 5,
    NGX_RTMP_NALU_SEI               = 6,
    NGX_RTMP_NALU_SPS               = 7,
    NGX_RTMP_NALU_PPS               = 8,
    NGX_RTMP_NALU_AUD               = 9,
    NGX_RTMP_NALU_EOSEQ             = 10,
    NGX_RTMP_NALU_EOSTREAM          = 11,
    NGX_RTMP_NALU_FILL              = 12,
    NGX_RTMP_NALU_SPS_EXT           = 13,
    NGX_RTMP_NALU_AUXILIARY_SLICE   = 19
};


/* AVC frame types */
enum {
    NGX_RTMP_FRAME_IDR              = 1,
    NGX_RTMP_FRAME_INTER            = 2,
    NGX_RTMP_FRAME_DISPOSABLE       = 3,
    NGX_RTMP_FRAME_GENERATED        = 4,
    NGX_RTMP_FRAME_VIDEOINFOCMD     = 5
};


/* Audio codecs */
enum {
    /* Uncompressed codec id is actually 0,
     * but we use another value for consistency */
    NGX_RTMP_AUDIO_UNCOMPRESSED     = 16,
    NGX_RTMP_AUDIO_ADPCM            = 1,
    NGX_RTMP_AUDIO_MP3              = 2,
    NGX_RTMP_AUDIO_LINEAR_LE        = 3,
    NGX_RTMP_AUDIO_NELLY16          = 4,
    NGX_RTMP_AUDIO_NELLY8           = 5,
    NGX_RTMP_AUDIO_NELLY            = 6,
    NGX_RTMP_AUDIO_G711A            = 7,
    NGX_RTMP_AUDIO_G711U            = 8,
    NGX_RTMP_AUDIO_AAC              = 10,
    NGX_RTMP_AUDIO_SPEEX            = 11,
    NGX_RTMP_AUDIO_MP3_8            = 14,
    NGX_RTMP_AUDIO_DEVSPEC          = 15
};


/* Video codecs */
enum {
    NGX_RTMP_VIDEO_JPEG             = 1,
    NGX_RTMP_VIDEO_SORENSON_H263    = 2,
    NGX_RTMP_VIDEO_SCREEN           = 3,
    NGX_RTMP_VIDEO_ON2_VP6          = 4,
    NGX_RTMP_VIDEO_ON2_VP6_ALPHA    = 5,
    NGX_RTMP_VIDEO_SCREEN2          = 6,
    NGX_RTMP_VIDEO_H264             = 7,
    NGX_RTMP_VIDEO_H265             = 12
};

/* hevc nal type */
enum {
    NAL_TRAIL_N    = 0,
    NAL_TRAIL_R    = 1,
    NAL_TSA_N      = 2,
    NAL_TSA_R      = 3,
    NAL_STSA_N     = 4,
    NAL_STSA_R     = 5,
    NAL_RADL_N     = 6,
    NAL_RADL_R     = 7,
    NAL_RASL_N     = 8,
    NAL_RASL_R     = 9,
    NAL_BLA_W_LP   = 16,
    NAL_BLA_W_RADL = 17,
    NAL_BLA_N_LP   = 18,
    NAL_IDR_W_RADL = 19,
    NAL_IDR_N_LP   = 20,
    NAL_CRA_NUT    = 21,
    NAL_VPS        = 32,
    NAL_SPS        = 33,
    NAL_PPS        = 34,
    NAL_AUD        = 35,
    NAL_EOS_NUT    = 36,
    NAL_EOB_NUT    = 37,
    NAL_FD_NUT     = 38,
    NAL_SEI_PREFIX = 39,
    NAL_SEI_SUFFIX = 40,
};


u_char * ngx_rtmp_get_audio_codec_name(ngx_uint_t id);
u_char * ngx_rtmp_get_video_codec_name(ngx_uint_t id);


#define NGX_RTMP_SPS_MAX_LENGTH            256

typedef struct {
    ngx_uint_t                  width;
    ngx_uint_t                  height;
    double                      duration;
    double                      frame_rate;
    double                      video_data_rate;
    ngx_uint_t                  video_codec_id;
    double                      audio_data_rate;
    ngx_uint_t                  audio_codec_id;
    ngx_uint_t                  aac_profile;
    ngx_uint_t                  aac_chan_conf;
    ngx_uint_t                  aac_sbr;
    ngx_uint_t                  aac_ps;
    ngx_uint_t                  avc_profile;
    ngx_uint_t                  avc_compat;
    ngx_uint_t                  avc_level;
    ngx_uint_t                  avc_nal_bytes;
    ngx_uint_t                  avc_ref_frames;
    ngx_uint_t                  sample_rate;    /* 5512, 11025, 22050, 44100 */
    ngx_uint_t                  sample_size;    /* 1=8bit, 2=16bit */
    ngx_uint_t                  audio_channels; /* 1, 2 */
    u_char                      profile[32];
    u_char                      level[32];

    ngx_chain_t                *avc_header;
    ngx_chain_t                *aac_header;

    ngx_chain_t                *meta;
    ngx_uint_t                  meta_version;
} ngx_rtmp_codec_ctx_t;


extern ngx_module_t  ngx_rtmp_codec_module;


#endif /* _NGX_RTMP_LIVE_H_INCLUDED_ */
