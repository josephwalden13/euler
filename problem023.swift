import Foundation

func getSieve(upperLimit:Int) -> [Int]
{
    var sieve:[Int] = Array(repeating: 0, count: upperLimit + 1)
    sieve[0] = 1
    sieve[1] = 1
    for i in 2 ... upperLimit
    {
        if sieve[i] == 0
        {
            for j in stride(from: 2 * i, to: upperLimit + 1, by: i)
            //for j in 2 * i ... upperLimit
            {
                sieve[j] = 1
            }
        }
    }
    return sieve
}

func getPrimes(upperLimit:Int) -> [Int]
{
    if upperLimit < 2
    {
        return []
    }
    var primes:[Int] = []
    for (index, i) in getSieve(upperLimit: upperLimit).enumerated()
    {
        if i == 0
        {
            primes.append(index)
        }
    }
    return primes
}

extension Int
{
    var Factors:[Int]
    {
        return getFactors(self)
    }
    var FactorSum:Int
    {
        var sum = 0
        for i in self.Factors
        {
            sum += i
        }
        return sum
    }
    var Abundant:Bool
    {
        return self.FactorSum > self
    }
    var Perfect:Bool
    {
        return self.FactorSum == self
    }
}

var primes = getPrimes(upperLimit: Int(sqrt(20161)) + 1)
var factorsCache:Dictionary<Int, [Int]> = [:]
func getFactors(_ num:Int) -> [Int]
{
    if factorsCache.keys.contains(num)
    {
        return factorsCache[num]!
    }
    if primes.contains(num)
    {
        return [num]
    }
    var factors:Set<Int> = []
    factors.update(with: 1)
    for i in primes.filter({
        x in
        x < num / 2 + 1 && num % x == 0
    })
    {
        //print("_\(i)")
        factors.update(with: i)
        if (num % i == 0)
        {
            factors.update(with: num / i)
            for factor in getFactors(num / i)
            {
                factors.update(with: factor)
            }
        }
    }
    var arr:[Int] = []
    for i in factors
    {
        arr.append(i)
    }
    factorsCache.updateValue(arr, forKey: num)
    return arr.sorted()
}

let max = 20161
var checked = 0
var total = 0

//create sieve
var sieve = Array(repeating: false, count: max + 1)
var abundants:[Int] = []
for (index, i) in sieve.enumerated()
{
    if index == 0
    {
        continue
    }
    if !sieve[index]
    {
        if index.Abundant
        {
            abundants.append(index)
            checked += 1
            total += 1
            //all multiples of abundant numbers are abundant so the loop marks them as true
            for j in stride(from: index * 2, to: sieve.count, by: index)
            {
                sieve[j] = true
            }
        }
    }
    else
    {
        abundants.append(index)
        total += 1
    }
}

//get all unique sum combos of abundant numbers
var combos:Set<Int> = []
for i in abundants
{
    for j in abundants
    {
        combos.update(with: i + j)
    }
}
print("\(combos.count) combos to check")

//go through each number 1...n and check if it is present in combo set. Print if not
var sum = 0
for i in 1...max
{
    if !combos.contains(i)
    {
        sum += i
    }
}
print("Sum: \(sum)")
print("Checked \(checked) / \(total)")
