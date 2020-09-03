<template>
  <div class="hello">
    <h1>{{ msg }}</h1>
    <p>
      Ini adalah aplikasi Internet of Things (IoT) sederhana. <br/> Untuk menyalakan lampu LED.
    </p>
    <h3>LED</h3>
    <ul>
      <li v-for="button in buttons" :key="button.id">
        {{ button.name }}
        <br/>
        {{ button.pin }}
        <br/>
        <div class="custom-control custom-switch">
          <input type="checkbox" class="custom-control-input" v-model="button.status" v-bind:id="button.id" @change="buttonEvent($event)">
          <label class="custom-control-label" v-bind:for="button.id"></label>
        </div>
      </li>
    </ul>
  </div>
</template>

<script>
const API_URL = 'http://your-api-url.com'
export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  data: () => {
    return {
      buttons: []
    }
  },
  created() {
    fetch(API_URL)
    .then(response => response.json())
    .then(json => {
      this.buttons = json
    })
  },
  methods: {
    buttonEvent: (e) => {
      let id = e.target.id
      let status = e.target.checked ? 1 : 0
      fetch(API_URL + id, {
        method: 'PATCH',
        body: JSON.stringify({
          id: e.target.id,
          status: status
        }),
        headers: {
          "content-type": "application/json"
        }
      })
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}

</style>
