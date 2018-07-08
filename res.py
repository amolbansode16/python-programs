
def get_res(branch,**subs):
    total=0
    for k,v in subs.items():
        if branch=="cse" and k in ["c","java"]:
            total+=v
    return total
sub={"c":20,"java":20,"math":10}
total=get_res("cse",C=20,java=20,math=10)
print(total)

