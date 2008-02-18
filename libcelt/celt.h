/* (C) 2007 Jean-Marc Valin, CSIRO
*/
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   
   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   
   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
   
   - Neither the name of the Xiph.org Foundation nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.
   
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CELT_H
#define CELT_H

#include "celt_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CELT_OK                0
#define CELT_BAD_ARG          -1
#define CELT_INVALID_MODE     -2
#define CELT_INTERNAL_ERROR   -3
#define CELT_CORRUPTED_DATA   -4

#define CELT_GET_FRAME_SIZE   1000
#define CELT_GET_LOOKAHEAD    1001
#define CELT_GET_NB_CHANNELS  1002
   
typedef struct CELTEncoder CELTEncoder;
typedef struct CELTDecoder CELTDecoder;

typedef struct CELTMode CELTMode;

/*extern const CELTMode *celt_mono;
extern const CELTMode *celt_stereo;
extern const CELTMode *celt_ld51;*/

#define celt_mono celt_mode_create(44100, 1, 256, 128)
#define celt_stereo celt_mode_create(44100, 2, 256, 128)
      
/* Encoder stuff */
CELTMode *celt_mode_create(int Fs, int channels, int frame_size, int overlap);

CELTEncoder *celt_encoder_new(const CELTMode *mode);

void celt_encoder_destroy(CELTEncoder *st);

int celt_encode(CELTEncoder *st, celt_int16_t *pcm, unsigned char *compressed, int nbCompressedBytes);

/* Decoder stuff */

CELTDecoder *celt_decoder_new(const CELTMode *mode);

void celt_decoder_destroy(CELTDecoder *st);

int celt_decode(CELTDecoder *st, unsigned char *data, int len, celt_int16_t *pcm);


/* Mode calls */

int celt_mode_info(const CELTMode *mode, int request, celt_int32_t *value);

#ifdef __cplusplus
}
#endif

#endif /*CELT_H */
