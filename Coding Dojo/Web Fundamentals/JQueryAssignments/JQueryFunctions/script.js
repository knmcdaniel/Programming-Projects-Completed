$(document).ready(function(){
    $("#buttonBlue").click(function(){
        $("#textBlue").css('color', 'blue')
    });

    $("#buttonHide").click(function(){
        $("#textHide").hide()
    });

    $("#buttonShow").click(function(){
        $("#textShow").show()
    });

    $("#buttonToggle").click(function(){
        $("#textToggle").toggle()
    });

    $("#buttonSlideDown").click(function(){
        $("#textSlideDown").slideDown(1000)
    });

    $("#buttonSlideUp").click(function(){
        $("#textSlideUp").slideUp(1000)
    });

    $("#buttonSlideToggle").click(function(){
        $("#textSlideToggle").slideToggle(1000)
    });

    $("#buttonFadeIn").click(function(){
        $("#textFadeIn").fadeIn(1000)
    });

    $("#buttonFadeOut").click(function(){
        $("#textFadeOut").fadeOut(1000)
    });

    $("#buttonAddClass").click(function(){
        $("#textAddClass").addClass("textAddClass")
    });

    $("#buttonBefore").click(function(){
        $("#textBefore").before("<p>Text added with before tag</p>")
    });

    $("#buttonAfter").click(function(){
        $("#textAfter").after("<p>Text added with After tag</p>")
    });

    $("#buttonAppend").click(function(){
        $("#textAppend").append(" This text was appended to the p tag.")
    });

    $("#buttonHTML").click(function(){
        $("#divHTML").html("<h3>Adding a header into the div via JQuery</h3>")
    });

    $("#buttonAttr").click(function(){
        $("#imgAttr").attr({
            alt: "alt content added via jQuery",
            title: "Title added via jQuery"
        })
    });

    //I know this appears to be copy/pasted from the website. I at first had the .click function working with a button but I wanted to experiment and see if this would work as well. After doing some research it looks like keyup can do a lot more than just print to a text box in real time. A lot of the information on the keyup page is way over my head. But its awesome to see this is possible. Oh and the .val is useful too :)

    $("#inputVal").keyup(function(){
        var liveInput = $(this).val()
        $("#textVal").text(liveInput)
    });

    $("#buttonText").click(function(){
        $("#textText").text("Replaced the text in this p tag.")
    });


})