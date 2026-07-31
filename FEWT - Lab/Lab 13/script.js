let arr = []
let editIndex = -1

$("#btnAdd").click(() => {
    let name = $("#textname").val()

    if (name == "") {
        alert("Enter Name: ")
        return
    }

    if (editIndex == -1) {
        arr.push(name)
    }
    else {
        arr[editIndex] = name
        editIndex = -1
        $("#btnAdd").text("Add")
    }

    $("#textname").val("")
    showData();
})

function showData() {
    let output = ""

    $.each(arr, function (index, value) {
        output += `
                <tr>
                    <td>${index + 1}</td>
                    <td>${value}</td>
                    <td>
                        <button onclick="editData(${index})">Edit</button>
                        <button onclick="deleteData(${index})">Delete</button>
                    </td>
                </tr>
                `
    })

    $("#tableData").html(output)
}

function editData(index) {
    editIndex = index
    $("#textname").val(arr[index])

    $("#btnAdd").text("Update")
}

function deleteData(index) {
    arr.splice(index, 1)
    showData()
}