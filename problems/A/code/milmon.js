const fs = require('fs')
const problem = fs.readFileSync('/dev/stdin').toString('ascii').trim().replace(/^CF/, '')

console.info(`https://codeforces.com/contest/${problem.replace(/[A-Z][0-9]{0,1}$/, '')}/problem/${problem.replace(/^\d+/, '')}`)
