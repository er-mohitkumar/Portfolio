
window.onload = function () {
    //Reference the DropDownList.
    var ddlYears = document.getElementById("ddlYears");

    //Determine the Current Year.
    var currentYear = (new Date()).getFullYear();

    //Loop and add the Year values to DropDownList.
    for (var i = 1995; i <= currentYear; i++) {
        var option = document.createElement("OPTION");
        option.innerHTML = i;
        option.value = i;
        ddlYears.appendChild(option);
    }
};
const scriptURL = 'https://script.google.com/macros/s/AKfycbzwzPOQm1BmxVA4gs-rZI3xhYZ-tMtxngYPfE7BkArhW_y_nTfFIKuX_BvaZUw9-KS0uQ/exec'
const form = document.forms['submit-to-google-sheet']


form.addEventListener('submit', e => {
    e.preventDefault()
    fetch(scriptURL, { method: 'POST', body: new FormData(form) })
        .then(response => {
            // msg.innerHTML = "Message sent Successfully"
            setTimeout(function () {
                alert("Message sent succesfully! Thanks for sharing your query with us.")
            }, 5)
            form.reset()
        })
        .catch(error => console.error('Error!', error.message))
})
function submit() {
    alert("You account details are submited! ")
}
function log() {
    alert("You have log in to your account")
}