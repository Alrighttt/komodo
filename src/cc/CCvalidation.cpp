/******************************************************************************
 * Copyright © 2014-2020 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

/*
 CCValidaton has common validation functions that should be used to validate some basic things in all CCs.
 */

#include "CCinclude.h"

bool FetchCCtx(uint256 txid, CTransaction& tx, struct CCcontract_info *cp)
{
    EvalRef eval; uint256 hashBlock;
    if (myGetTransaction(txid,tx,hashBlock)==0) return (false);
    return (ValidateCCtx(tx,cp));
}

bool ValidateCCtx(const CTransaction& tx, struct CCcontract_info *cp)
{
    EvalRef eval;
    if (cp->validate(cp,eval.get(),tx,0)) return (true);
    return (false);
}
