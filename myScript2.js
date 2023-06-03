function calculate(){
var x,y,w,z,total,discount,adiscount,Final;
w=document.getElementById("wnumb").value;
x=document.getElementById("xnumb").value;
y=document.getElementById("ynumb").value;
z=document.getElementById("znumb").value;
total=Number(w)+Number(x)+Number(y)+Number(z);
document.getElementById("total").value=total;
if(total>=10000){
	discount=Number(total)*20/100;
}
else{
	discount=Number(total)*10/100;
}
document.getElementById("discount").value=discount;
adiscount=Number(total)-Number(discount);
document.getElementById("adiscount").value=adiscount;
sgst=Number(adiscount)*5/100;
document.getElementById("sgst").value=sgst;
cgst=Number(adiscount)*5/100;
document.getElementById("cgst").value=cgst;
Final=Number(adiscount)+Number(sgst)+Number(cgst);
document.getElementById("Final").value=Final;
}