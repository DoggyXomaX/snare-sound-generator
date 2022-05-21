#ifndef __WAVE_FORMAT_H__
#define __WAVE_FORMAT_H__

/* https://audiocoding.ru/articles/2008-05-22-wav-file-structure/wav_formats.txt */

#define WAVE_FORMAT_UNKNOWN                 0x0000
#define WAVE_FORMAT_PCM                     0x0001
#define WAVE_FORMAT_ADPCM                   0x0002
#define WAVE_FORMAT_IEEE_FLOAT              0x0003
#define WAVE_FORMAT_VSELP                   0x0004
#define WAVE_FORMAT_IBM_CVSD                0x0005
#define WAVE_FORMAT_ALAW                    0x0006
#define WAVE_FORMAT_MULAW                   0x0007
#define WAVE_FORMAT_DTS                     0x0008
#define WAVE_FORMAT_DRM                     0x0009
#define WAVE_FORMAT_OKI_ADPCM               0x0010
#define WAVE_FORMAT_DVI_ADPCM               0x0011
#define WAVE_FORMAT_IMA_ADPCM               0x0011
#define WAVE_FORMAT_MEDIASPACE_ADPCM        0x0012
#define WAVE_FORMAT_SIERRA_ADPCM            0x0013
#define WAVE_FORMAT_G723_ADPCM              0x0014
#define WAVE_FORMAT_DIGISTD                 0x0015
#define WAVE_FORMAT_DIGIFIX                 0x0016
#define WAVE_FORMAT_DIALOGIC_OKI_ADPCM      0x0017
#define WAVE_FORMAT_MEDIAVISION_ADPCM       0x0018
#define WAVE_FORMAT_CU_CODEC                0x0019
#define WAVE_FORMAT_YAMAHA_ADPCM            0x0020
#define WAVE_FORMAT_SONARC                  0x0021
#define WAVE_FORMAT_DSPGROUP_TRUESPEECH     0x0022
#define WAVE_FORMAT_ECHOSC1                 0x0023
#define WAVE_FORMAT_AUDIOFILE_AF3           0x0024
#define WAVE_FORMAT_APTX                    0x0025
#define WAVE_FORMAT_AUDIOFILE_AF1           0x0026
#define WAVE_FORMAT_PROSODY_1612            0x0027
#define WAVE_FORMAT_LRC                     0x0028
#define WAVE_FORMAT_DOLBY_AC2               0x0030
#define WAVE_FORMAT_GSM610                  0x0031
#define WAVE_FORMAT_MSNAUDIO                0x0032
#define WAVE_FORMAT_ANTEX_ADPCME            0x0033
#define WAVE_FORMAT_CONTROL_RES_VQLPC       0x0034
#define WAVE_FORMAT_DIGIREAL                0x0035
#define WAVE_FORMAT_DIGIADPCM               0x0036
#define WAVE_FORMAT_CONTROL_RES_CR10        0x0037
#define WAVE_FORMAT_NMS_VBXADPCM            0x0038
#define WAVE_FORMAT_CS_IMAADPCM             0x0039
#define WAVE_FORMAT_ECHOSC3                 0x003A
#define WAVE_FORMAT_ROCKWELL_ADPCM          0x003B
#define WAVE_FORMAT_ROCKWELL_DIGITALK       0x003C
#define WAVE_FORMAT_XEBEC                   0x003D
#define WAVE_FORMAT_G721_ADPCM              0x0040
#define WAVE_FORMAT_G728_CELP               0x0041
#define WAVE_FORMAT_MSG723                  0x0042
#define WAVE_FORMAT_MPEG                    0x0050
#define WAVE_FORMAT_RT24                    0x0052
#define WAVE_FORMAT_PAC                     0x0053
#define WAVE_FORMAT_MPEGLAYER3              0x0055
#define WAVE_FORMAT_LUCENT_G723             0x0059
#define WAVE_FORMAT_CIRRUS                  0x0060
#define WAVE_FORMAT_ESPCM                   0x0061
#define WAVE_FORMAT_VOXWARE                 0x0062
#define WAVE_FORMAT_CANOPUS_ATRAC           0x0063
#define WAVE_FORMAT_G726_ADPCM              0x0064
#define WAVE_FORMAT_G722_ADPCM              0x0065
#define WAVE_FORMAT_DSAT_DISPLAY            0x0067
#define WAVE_FORMAT_VOXWARE_BYTE_ALIGNED    0x0069
#define WAVE_FORMAT_VOXWARE_AC8             0x0070
#define WAVE_FORMAT_VOXWARE_AC10            0x0071
#define WAVE_FORMAT_VOXWARE_AC16            0x0072
#define WAVE_FORMAT_VOXWARE_AC20            0x0073
#define WAVE_FORMAT_VOXWARE_RT24            0x0074
#define WAVE_FORMAT_VOXWARE_RT29            0x0075
#define WAVE_FORMAT_VOXWARE_RT29HW          0x0076
#define WAVE_FORMAT_VOXWARE_VR12            0x0077
#define WAVE_FORMAT_VOXWARE_VR18            0x0078
#define WAVE_FORMAT_VOXWARE_TQ40            0x0079
#define WAVE_FORMAT_SOFTSOUND               0x0080
#define WAVE_FORMAT_VOXWARE_TQ60            0x0081
#define WAVE_FORMAT_MSRT24                  0x0082
#define WAVE_FORMAT_G729A                   0x0083
#define WAVE_FORMAT_MVI_MVI2                0x0084
#define WAVE_FORMAT_DF_G726                 0x0085
#define WAVE_FORMAT_DF_GSM610               0x0086
#define WAVE_FORMAT_ISIAUDIO                0x0088
#define WAVE_FORMAT_ONLIVE                  0x0089
#define WAVE_FORMAT_SBC24                   0x0091
#define WAVE_FORMAT_DOLBY_AC3_SPDIF         0x0092
#define WAVE_FORMAT_MEDIASONIC_G723         0x0093
#define WAVE_FORMAT_PROSODY_8KBPS           0x0094
#define WAVE_FORMAT_ZYXEL_ADPCM             0x0097
#define WAVE_FORMAT_PHILIPS_LPCBB           0x0098
#define WAVE_FORMAT_PACKED                  0x0099
#define WAVE_FORMAT_MALDEN_PHONYTALK        0x00A0
#define WAVE_FORMAT_RHETOREX_ADPCM          0x0100
#define WAVE_FORMAT_IRAT                    0x0101
#define WAVE_FORMAT_VIVO_G723               0x0111
#define WAVE_FORMAT_VIVO_SIREN              0x0112
#define WAVE_FORMAT_DIGITAL_G723            0x0123
#define WAVE_FORMAT_SANYO_LD_ADPCM          0x0125
#define WAVE_FORMAT_SIPROLAB_ACEPLNET       0x0130
#define WAVE_FORMAT_SIPROLAB_ACELP4800      0x0131
#define WAVE_FORMAT_SIPROLAB_ACELP8V3       0x0132
#define WAVE_FORMAT_SIPROLAB_G729           0x0133
#define WAVE_FORMAT_SIPROLAB_G729A          0x0134
#define WAVE_FORMAT_SIPROLAB_KELVIN         0x0135
#define WAVE_FORMAT_G726ADPCM               0x0140
#define WAVE_FORMAT_QUALCOMM_PUREVOICE      0x0150
#define WAVE_FORMAT_QUALCOMM_HALFRATE       0x0151
#define WAVE_FORMAT_TUBGSM                  0x0155
#define WAVE_FORMAT_MSAUDIO1                0x0160
#define WAVE_FORMAT_UNISYS_NAP_ADPCM        0x0170
#define WAVE_FORMAT_UNISYS_NAP_ULAW         0x0171
#define WAVE_FORMAT_UNISYS_NAP_ALAW         0x0172
#define WAVE_FORMAT_UNISYS_NAP_16K          0x0173
#define WAVE_FORMAT_CREATIVE_ADPCM          0x0200
#define WAVE_FORMAT_CREATIVE_FASTSPEECH8    0x0202
#define WAVE_FORMAT_CREATIVE_FASTSPEECH10   0x0203
#define WAVE_FORMAT_UHER_ADPCM              0x0210
#define WAVE_FORMAT_QUARTERDECK             0x0220
#define WAVE_FORMAT_ILINK_VC                0x0230
#define WAVE_FORMAT_RAW_SPORT               0x0240
#define WAVE_FORMAT_ESST_AC3                0x0241
#define WAVE_FORMAT_IPI_HSX                 0x0250
#define WAVE_FORMAT_IPI_RPELP               0x0251
#define WAVE_FORMAT_CS2                     0x0260
#define WAVE_FORMAT_SONY_SCX                0x0270
#define WAVE_FORMAT_FM_TOWNS_SND            0x0300
#define WAVE_FORMAT_BTV_DIGITAL             0x0400
#define WAVE_FORMAT_QDESIGN_MUSIC           0x0450
#define WAVE_FORMAT_VME_VMPCM               0x0680
#define WAVE_FORMAT_TPC                     0x0681
#define WAVE_FORMAT_OLIGSM                  0x1000
#define WAVE_FORMAT_OLIADPCM                0x1001
#define WAVE_FORMAT_OLICELP                 0x1002
#define WAVE_FORMAT_OLISBC                  0x1003
#define WAVE_FORMAT_OLIOPR                  0x1004
#define WAVE_FORMAT_LH_CODEC                0x1100
#define WAVE_FORMAT_NORRIS                  0x1400
#define WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS 0x1500
#define WAVE_FORMAT_DVM                     0x2000

#endif