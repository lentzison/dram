<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>D&D Cocktails</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 0;
                padding: 20px;
            }
    
            .header {
                background-color: #ffffff;
                padding: 20px;
                text-align: center;
                box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            }
    
            h1 {
                color: #333;
            }
    
            h2 {
                color: #555;
            }
    
            #search {
                margin-bottom: 20px;
                display: flex;
                flex-wrap: wrap;
                justify-content: space-between;
            }
    
            select, input {
                margin-bottom: 20px;
                width: 100%;
                padding: 10px;
                border: 1px solid #ccc;
                border-radius: 5px;
                box-shadow: 0 0 5px rgba(0, 0, 0, 0.05);
            }
    
            #recipes {
                display: flex;
                flex-wrap: wrap;
                justify-content: space-between;
            }
    
            .recipe {
                display: none;
                background-color: #fff;
                padding: 20px;
                border-radius: 5px;
                box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
                margin-bottom: 20px;
                width: 100%; /* Full width on mobile */
                box-sizing: border-box;
            }
    
            @media (min-width: 600px) {
                #search input, #search select {
                    width: 48%;
                }
    
                .recipe {
                    width: 48%; /* Side by side on larger screens */
                }
            }
    
            .image-placeholder {
                width: 100px;
                height: 100px;
                background-image: url('placeholder.png');
                background-size: cover;
                margin: 10px auto;
                display: block;
            }
        </style>
   <script>
    console.log("Before sorting:", cocktailsArray);
    var families = [];
    var categories = [];
    var cocktailsArray = []; // New array to hold cocktails

    window.onload = function() {
        fetch('get_cocktails.php')
            .then(response => response.json())
            .then(cocktails => {
                var dropdown = document.getElementById('dropdown');
                var familyDropdown = document.getElementById('familyDropdown');
                var categoryDropdown = document.getElementById('categoryDropdown');
                var recipesDiv = document.getElementById('recipes');

                cocktails.forEach(cocktail => {
                    cocktailsArray.push({id: cocktail.id, name: cocktail.name}); // Add cocktail to array

                    if (!families.includes(cocktail.family)) {
                        families.push(cocktail.family);
                    }

                    if (!categories.includes(cocktail.category)) {
                        categories.push(cocktail.category);
                    }

                    var recipeDiv = document.createElement('div');
                    recipeDiv.className = 'recipe';
                    recipeDiv.id = cocktail.id;
                    recipeDiv.innerHTML = `
                        <!-- (HTML code for the recipe) -->
                    `;
                    recipesDiv.appendChild(recipeDiv);
                });
                console.log("After sorting:", cocktailsArray);
                // Sort and append families
                families.sort();
                families.forEach(family => {
                    var familyOption = document.createElement('option');
                    familyOption.value = family;
                    familyOption.textContent = family;
                    familyDropdown.appendChild(familyOption);
                });

                // Sort and append categories
                categories.sort();
                categories.forEach(category => {
                    var categoryOption = document.createElement('option');
                    categoryOption.value = category;
                    categoryOption.textContent = category;
                    categoryDropdown.appendChild(categoryOption);
                });

                // Sort and append cocktails
                cocktailsArray.sort((a, b) => a.name.localeCompare(b.name));
                cocktailsArray.forEach(cocktail => {
                    var option = document.createElement('option');
                    option.value = cocktail.id;
                    option.textContent = cocktail.name;
                    dropdown.appendChild(option);
                });
            })
            .catch(error => console.error('An error occurred:', error));
    };

                        var recipeDiv = document.createElement('div');
                        recipeDiv.className = 'recipe';
                        recipeDiv.id = cocktail.id;
                        recipeDiv.innerHTML = `
                            <div class="image-placeholder" style="background-image: url('${cocktail.image_url}');"></div>
                            <h2>${cocktail.name}</h2>
                            <p><strong>Family:</strong> ${cocktail.family}</p>
                            <p><strong>Category:</strong> ${cocktail.category}</p>
                            <p><strong>Ingredients:</strong></p>
                            <ul>${cocktail.ingredients.split(',').map(ingredient => `<li>${ingredient}</li>`).join('')}</ul>
                            <p><strong>Glassware:</strong> ${cocktail.glassware}</p>
                            <p><strong>Garnish:</strong> ${cocktail.garnish}</p>
                            <p><strong>Instructions:</strong> ${cocktail.instructions}</p>
                        `;
                        recipesDiv.appendChild(recipeDiv);
                    });
                })
                .catch(error => console.error('An error occurred:', error));
        };

        function showRecipe(id) {
    var recipes = document.getElementsByClassName('recipe');
    if (id === 'all') { // If "Show All" is selected
        for (var i = 0; i < recipes.length; i++) {
            recipes[i].style.display = 'block';
        }
    } else {
        for (var i = 0; i < recipes.length; i++) {
            recipes[i].style.display = 'none';
        }
        document.getElementById(id).style.display = 'block';
    }
}




        function searchRecipe() {
    var input = document.getElementById('searchInput').value.toLowerCase();
    var recipes = document.getElementsByClassName('recipe');
    for (var i = 0; i < recipes.length; i++) {
        var title = recipes[i].getElementsByTagName('h2')[0].innerText.toLowerCase();
        recipes[i].style.display = title.includes(input) ? 'block' : 'none';
    }
}



        function filterByFamily() {
            var family = document.getElementById('familyDropdown').value;
            var recipes = document.getElementsByClassName('recipe');
            for (var i = 0; i < recipes.length; i++) {
                var recipeFamily = recipes[i].getElementsByTagName('p')[0].innerText.split(': ')[1];
                recipes[i].style.display = family === '' || family === recipeFamily ? 'block' : 'none';
            }
        }

        function filterByCategory() {
            var category = document.getElementById('categoryDropdown').value;
            var recipes = document.getElementsByClassName('recipe');
            for (var i = 0; i < recipes.length; i++) {
                var recipeCategory = recipes[i].getElementsByTagName('p')[1].innerText.split(': ')[1];
                recipes[i].style.display = category === '' || category === recipeCategory ? 'block' : 'none';
            }
        }
    </script>
</head>
<body>
    <div class="header">
        <!-- Removed logo -->
    </div>
    <div style="padding: 20px;">
        <h1>D&D Cocktails</h1>
        <div id="search">
            <input type="text" id="searchInput" onkeyup="searchRecipe()" placeholder="Search for cocktails...">
            <select id="dropdown" onchange="showRecipe(this.value)">
                <option value="">Select a cocktail...</option>
                <option value="all">Show All</option> <!-- New option to show all -->
                <!-- Options will be populated dynamically -->
            </select>
            
            <select id="familyDropdown" onchange="filterByFamily()">
                <option value="">Filter by family...</option>
                <!-- Options will be populated dynamically -->
            </select>
            <select id="categoryDropdown" onchange="filterByCategory()">
                <option value="">Filter by category...</option>
                <!-- Options will be populated dynamically -->
            </select>
        </div>
        <div id="recipes">
            <!-- Recipe divs will be populated dynamically -->
        </div>
    </div>
</body>
</html>
