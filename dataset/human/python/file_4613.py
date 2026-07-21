def jp(Y):
    if Y > 1988:
        return f"H{Y-1988}"
    elif Y > 1925:
        return f"S{Y-1925}"
    elif Y > 1911:
        return f"T{Y-1911}"
    elif Y > 1911:
        return f"T{Y-1911}"
    else:
        return f"M{Y-1867}"

def meiji(Y):
    return f"{1867+Y}"

def taisho(Y):
    return f"{1911+Y}"

def syowa(Y):
    return f"{1925+Y}"

def heisei(Y):
    return f"{1988+Y}"

E, Y = map(int, input().split())
print([jp(Y), meiji(Y), taisho(Y), syowa(Y), heisei(Y)][E])
