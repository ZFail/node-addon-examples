var addon = require('bindings')('addon.node')

const buf = Buffer.alloc(16, '0123456789012345')

console.log('This should be 0123456789012345:', buf.toString())
console.log('This should be 01:', addon.createExternalBuffer(buf, 2).toString())
console.log('This should be 0123:', addon.createExternalBuffer(buf, 4).toString())