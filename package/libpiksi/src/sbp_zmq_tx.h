/*
 * Copyright (C) 2017 Swift Navigation Inc.
 * Contact: Jacob McNamee <jacob@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef LIBPIKSI_SBP_ZMQ_TX_H
#define LIBPIKSI_SBP_ZMQ_TX_H

#include "common.h"

typedef struct sbp_zmq_tx_ctx_s sbp_zmq_tx_ctx_t;

sbp_zmq_tx_ctx_t * sbp_zmq_tx_create(zsock_t *zsock);
void sbp_zmq_tx_destroy(sbp_zmq_tx_ctx_t **ctx);

int sbp_zmq_tx_send(sbp_zmq_tx_ctx_t *ctx, u16 msg_type, u8 len, u8 *payload);
int sbp_zmq_tx_send_from(sbp_zmq_tx_ctx_t *ctx, u16 msg_type, u8 len,
                         u8 *payload, u16 sbp_sender_id);

#endif /* LIBPIKSI_SBP_ZMQ_TX_H */
