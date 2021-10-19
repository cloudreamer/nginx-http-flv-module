
# 说明
参考[AlexWoo](https://github.com/AlexWoo/nginx-rtmp-module) 在http-flv-module中增加http-flv对h265的支持.
~~~
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
~~~
# flv h265
参考[ksvc ffmpeg](https://github.com/ksvc/FFmpeg)对flv h265的扩展

# 效果
实测对海康、大华、宇视的h265码流均有效

# 编译
是在nginx-1.18 编译验证，其他版本未验证
