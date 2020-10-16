//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

import Foundation

var units = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
extension Int
{
    var InEnglish:String
    {
        if self < 10
        {
            return units[self - 1]
        }
        else if self < 20
        {
            switch self - 10 {
            case 0:
                return "ten"
            case 1:
                return "eleven"
            case 2:
                return "twelve"
            case 3:
                return "thirteen"
            case 5:
                return "fifteen"
            case 8:
                return "eighteen"
            default:
                return (self - 10).InEnglish + "teen"
            }
        }
        else if self < 100
        {
            if self % 10 == 0
            {
                switch self / 10 {
                case 2:
                    return "twenty"
                case 3:
                    return "thirty"
                case 4:
                    return "forty"
                case 5:
                    return "fifty"
                case 8:
                    return "eighty"
                default:
                    return
                        (self / 10).InEnglish + "ty"
                }
            }
            else
            {
                return Int(floor(Double(self) / 10) * 10).InEnglish + (self % 10).InEnglish
            }
        }
        else if self < 1000
        {
            if self % 100 == 0
            {
                return (self / 100).InEnglish + "hundred"
            }
            else
            {
                return Int(floor(Double(self) / 100) * 100).InEnglish + "and" + (self % 100).InEnglish
            }
        }
        else if self == 1000
        {
            return "onethousand"
        }
        return ""
    }
}

print("Calculating")
var sum = 0
for i in 1 ... 1000
{
    sum += i.InEnglish.count
}
print("Length: \(sum)")
